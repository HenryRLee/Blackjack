all: Blackjack EV

Blackjack: Blackjack.o Card.o Dealer.o Deck.o Gambler.o Game.o \
		MacauSimulation.o Player.o ShuffleMachine.o Table.o \
		ContinuousShufflingMachine.o Hand.o Statistics.o StreamLog.o \
		Strategy.o BasicStrategy.o  NoStrategy.o LongTermStats.o \
		EnhancedStrategy.o UsedCard.o
	g++ ${CFLAGS} $^ -o $@

EV: EV.o ProbabilityCalculator.o SimpleCalculator.o AdvancedFastCalculator.o \
		SimpleFastCalculator.o AdvancedCalculator.o Card.o UsedCard.o
	g++ ${CFLAGS} $^ -o $@

Martingale: Martingale.c
	gcc Martingale.c -o Martingale

%.o: %.cpp
	g++ ${CFLAGS} $< -c -o $@

clean:
	rm -f *.o Blackjack EV Martingale
