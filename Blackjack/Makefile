all: Blackjack EV

Blackjack: Blackjack.o Card.o Dealer.o Deck.o Gambler.o Game.o \
		MacauSimulation.o Player.o ShuffleMachine.o Table.o \
		ContinuousShufflingMachine.o Hand.o Statistics.o StreamLog.o \
		Strategy.o BasicStrategy.o ProbabilityCalculator.o SimpleCalculator.o \
		NoStrategy.o LongTermStats.o
	g++ $^ ${CFLAGS} -o $@

EV: EV.o ProbabilityCalculator.o SimpleCalculator.o
	g++ $^ ${CFLAGS} -o $@

%.o: %.cpp
	g++ $< ${CFLAGS} -c -o $@

clean:
	rm -f *.o Blackjack
