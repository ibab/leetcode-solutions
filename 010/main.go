package main

// Possible states of the automaton
type Type int

const (
	LITERAL Type = iota
	DOT
	FLOW
	MATCH
)

type State struct {
	// State of the automaton
	typ Type
	// Which character to match, if this is a literal
	char byte
	// Regular control flow
	left *State
	// Special control flow
	right *State
	// Used to perform efficient set membership lookup
	visited int
}

// A stack of automaton states.
// Used when parsing the regular expression
type Stack []*State

func (s *Stack) Push(v *State) {
	*s = append(*s, v)
}

func (s *Stack) Pop() *State {
	res := (*s)[len(*s)-1]
	*s = (*s)[:len(*s)-1]
	return res
}

// Creates an automaton from the pattern p
func BuildAutomaton(p string) *State {
	stack := Stack{}
	start := &State{FLOW, 0, nil, nil, 0}
	stack.Push(start)
	for i := 0; i < len(p); i++ {
		switch p[i] {
		case '.':
			last := stack.Pop()
			curr := &State{DOT, 0, nil, nil, 0}
			last.left = curr
			stack.Push(last)
			stack.Push(curr)
		case '*':
			last1 := stack.Pop()
			last2 := stack.Pop()
			flow := &State{FLOW, 0, nil, nil, 0}
			last2.left = flow
			flow.right = last1
			last1.left = flow
			stack.Push(last2)
			stack.Push(flow)
		case '+':
			last := stack.Pop()
			last.right = last
			stack.Push(last)
		default:
			last := stack.Pop()
			curr := &State{LITERAL, p[i], nil, nil, 0}
			last.left = curr
			stack.Push(last)
			stack.Push(curr)
		}
	}
	last := stack.Pop()
	last.left = &State{MATCH, 0, nil, nil, 0}

	return start
}

type StateSet []*State

// Adds all new states reachable by following control flow states
func AddState(states StateSet, state *State, visited int) StateSet {
	if state == nil || state.visited == visited {
		return states
	}
	if state.typ == FLOW {
		states = AddState(states, state.left, visited)
		states = AddState(states, state.right, visited)
		return states
	}
	state.visited = visited
	return append(states, state)
}

// Advances the automaton by one character
// Keeps track of all currently occupied states
func Advance(states StateSet, char byte, visited int) StateSet {
	next := StateSet{}
	for i := 0; i < len(states); i++ {
		s := states[i]
		if s.typ != LITERAL || s.char == char {
			next = AddState(next, s.left, visited)
		}
	}
	return next
}

// Check whether the string s matches the pattern s
// This steps through all characters of the string,
// advancing the automaton each time
// We know that the string matches the pattern if the MATCH state
// is an occupied state at the end of the iteration
func isMatch(s string, p string) bool {
	automaton := BuildAutomaton(p)
	visited := 1

	states := StateSet{}
	states = append(states, automaton)
	states = Advance(states, 0, visited)
	visited++

	for i := 0; i < len(s); i++ {
		states = Advance(states, s[i], visited)
		visited++
	}

	for i := 0; i < len(states); i++ {
		if states[i].typ == MATCH {
			return true
		}
	}
	return false
}

func main() {
	println(isMatch("aaabc", "a*b+c*"))
}
