#include <iostream>
using namespace std;


class Race {
private:
    long maxTime;
    long distance;

    bool isWinningStrategy(long timeButton) {
        return (timeButton * (maxTime - timeButton) > distance);
    }

    long findLeft() {
        long indexLeft = 1;
        while (!isWinningStrategy(indexLeft)) {
            indexLeft++;
        }
        return indexLeft;
    }


    long findRight() {
        long indexRight = maxTime-1;
        while (!isWinningStrategy(indexRight)) {
            indexRight--;
        }
        return indexRight;
    }

public:
    Race(long max, long d) {
        maxTime = max;
        distance = d;
    }

    long numWinningStrategies() {
        long indexLeft = findLeft();
        long indexRight = findRight();
        return indexRight-indexLeft+1;
    }
};

int main(int argc, char **argv) {
    // Part 1
    Race race1(61, 430);
    Race race2(67, 1036);
    Race race3(75, 1307);
    Race race4(71, 1150);

    long numWinningStrategies = race1.numWinningStrategies();
    numWinningStrategies *= race2.numWinningStrategies();
    numWinningStrategies *= race3.numWinningStrategies();
    numWinningStrategies *= race4.numWinningStrategies();

    cout << "The total for part 1 is " << numWinningStrategies << '\n';

    // Part 2
    Race race5(61677571, 430103613071150);

    numWinningStrategies = race5.numWinningStrategies();
    cout << "The total for part 2 is " << numWinningStrategies << '\n';

    return 0;
}
