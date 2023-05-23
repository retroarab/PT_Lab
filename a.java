import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SomeRandomTest {

    enum IntervalType {
        OPEN,
        OPEN_RIGHT,
        OPEN_LEFT,
        CLOSED
    }

    @Test
    public void testNumberInRange() {
        Range openRange = createRange(0, 100, IntervalType.OPEN);
        Range openRightRange = createRange(0, 100, IntervalType.OPEN_RIGHT);
        Range openLeftRange = createRange(0, 100, IntervalType.OPEN_LEFT);
        Range closedRange = createRange(0, 100, IntervalType.CLOSED);

        // Test within range
        assertTrue(openRange.isNumberInRange(50));
        assertTrue(openRightRange.isNumberInRange(50));
        assertTrue(openLeftRange.isNumberInRange(50));
        assertTrue(closedRange.isNumberInRange(50));

        // Test at the lower bound
        assertFalse(openRange.isNumberInRange(0));
        assertFalse(openRightRange.isNumberInRange(0));
        assertTrue(openLeftRange.isNumberInRange(0));
        assertTrue(closedRange.isNumberInRange(0));

        // Test at the upper bound
        assertFalse(openRange.isNumberInRange(100));
        assertTrue(openRightRange.isNumberInRange(100));
        assertFalse(openLeftRange.isNumberInRange(100));
        assertTrue(closedRange.isNumberInRange(100));
    }

    @Test
    public void testNumberNotInRange() {
        Range openRange = createRange(0, 100, IntervalType.OPEN);
        Range openRightRange = createRange(0, 100, IntervalType.OPEN_RIGHT);
        Range openLeftRange = createRange(0, 100, IntervalType.OPEN_LEFT);
        Range closedRange = createRange(0, 100, IntervalType.CLOSED);

        // Test below the range
        assertFalse(openRange.isNumberInRange(-10));
        assertFalse(openRightRange.isNumberInRange(-10));
        assertFalse(openLeftRange.isNumberInRange(-10));
        assertFalse(closedRange.isNumberInRange(-10));

        // Test above the range
        assertFalse(openRange.isNumberInRange(150));
        assertFalse(openRightRange.isNumberInRange(150));
        assertFalse(openLeftRange.isNumberInRange(150));
        assertFalse(closedRange.isNumberInRange(150));

        // Test below the range by one unit
        assertFalse(openRange.isNumberInRange(-1));
        assertFalse(openRightRange.isNumberInRange(-1));
        assertFalse(openLeftRange.isNumberInRange(-1));
        assertFalse(closedRange.isNumberInRange(-1));

        // Test above the range by one unit
        assertFalse(openRange.isNumberInRange(101));
        assertFalse(openRightRange.isNumberInRange(101));
        assertFalse(openLeftRange.isNumberInRange(101));
        assertFalse(closedRange.isNumberInRange(101));
    }

    private Range createRange(int min, int max, IntervalType intervalType) {
        switch (intervalType) {
            case OPEN:
                return new Range(min, max, false, false);
            case OPEN_RIGHT:
                return new Range(min, max, false, true);
            case OPEN_LEFT:
                return new Range(min, max, true, false);
            case CLOSED:
                return new Range(min, max, true, true);
            default:
                throw new IllegalArgumentException("Invalid interval type");
        }
    }

    static class Range {
        private int min;
        private int max;
        private boolean includeLeftBound;
        private boolean includeRightBound;

        public Range(int min, int max, boolean includeLeftBound, boolean includeRightBound) {
            this.min = min;
            this.max = max;
            this.includeLeftBound = includeLeftBound;
            this.includeRightBound = includeRightBound;
        }

        public boolean isNumberInRange(int number) {
            if (includeLeftBound && number < min) {
                return false;
            }
            if (!includeLeftBound && number <= min) {
                return false;
            }
            if (includeRightBound && number > max) {
                return false;
            }
            if (!includeRightBound && number >= max) {
                return false;
            }
            return true;
        }
    }
}
