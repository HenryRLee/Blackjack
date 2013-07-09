all: Blackjack

Blackjack: Blackjack.o Card.o Dealer.o Deck.o Gambler.o Game.o \
		MacauSimulation.o Player.o ShuffleMachine.o Table.o \
		ContinuousShufflingMachine.o Hand.o
	g++ $^ -g -o $@

%.o: %.cpp
	g++ $< -g -c -o $@

clean:
	rm -f *.o Blackjack
