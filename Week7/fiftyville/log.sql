-- Check description of crime scene reports on July 28th, 2025
SELECT description FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28;
-- Theft took place at 10:15am
-- Interview of 3 witnesses conducted

-- Check the transcript of interview of all the witnesses
SELECT transcript FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28;
-- Thief drove away within 10mins (Look for information in bakery security logs)
-- Thief withdrew money from ATM on Leggett Street early that morning
-- Thief called someone while leaving the bakery for less than 60sec. They were planning to take the earliest flight out of Fiftyville tomorrow
-- Thief asked the person on phone to purchase flight ticket

-- Check the license plates of the suspects
SELECT license_plate FROM bakery_security_logs
WHERE year = 2025
AND month = 7
AND day = 28
AND (minute > 15 AND minute < 25)
AND activity = "exit";
-- +---------------+
-- | license_plate |
-- +---------------+
-- | 5P2BI95       |
-- | 94KL13X       |
-- | 6P58WS2       |
-- | 4328GD8       |
-- | G412CB7       |
-- | L93JTIZ       |
-- | 322W7JE       |
-- | 0NTHK55       |
-- | NAW9653       |
-- | 94MV71O       |
-- | V47T75I       |
-- | R3G7486       |
-- +---------------+

-- Check the account numbers of the suspects
SELECT account_number FROM atm_transactions
WHERE year = 2025
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
and transaction_type = "withdraw";
-- +----------------+
-- | account_number |
-- +----------------+
-- | 28500762       |
-- | 28296815       |
-- | 76054385       |
-- | 49610011       |
-- | 16153065       |
-- | 25506511       |
-- | 81061156       |
-- | 26013199       |
-- +----------------+

-- Check for person_id of suspects
SELECT person_id FROM bank_accounts
WHERE account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND atm_location = "Leggett Street"
    and transaction_type = "withdraw"
);
-- +-----------+
-- | person_id |
-- +-----------+
-- | 686048    |
-- | 514354    |
-- | 458378    |
-- | 395717    |
-- | 396669    |
-- | 467400    |
-- | 449774    |
-- | 438727    |
-- +-----------+

-- Check name, phone_number, passport_number of suspects
SELECT name, phone_number, passport_number FROM people
WHERE id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2025
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
        and transaction_type = "withdraw"
    )
);
-- +---------+----------------+-----------------+
-- |  name   |  phone_number  | passport_number |
-- +---------+----------------+-----------------+
-- | Kenny   | (826) 555-1652 | 9878712108      |
-- | Iman    | (829) 555-5269 | 7049073643      |
-- | Benista | (338) 555-6650 | 9586786673      |
-- | Taylor  | (286) 555-6063 | 1988161715      |
-- | Brooke  | (122) 555-4581 | 4408372428      |
-- | Luca    | (389) 555-5198 | 8496433585      |
-- | Diana   | (770) 555-1861 | 3592750733      |
-- | Bruce   | (367) 555-5533 | 5773159633      |
-- +---------+----------------+-----------------+

-- Check for call logs in the time frame during which thief was on call with accomplice
SELECT caller, receiver FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration < 60;
-- +----------------+----------------+
-- |     caller     |    receiver    |
-- +----------------+----------------+
-- | (130) 555-0289 | (996) 555-8899 |
-- | (499) 555-9472 | (892) 555-8872 |
-- | (367) 555-5533 | (375) 555-8161 |
-- | (499) 555-9472 | (717) 555-1342 |
-- | (286) 555-6063 | (676) 555-6554 |
-- | (770) 555-1861 | (725) 555-3243 |
-- | (031) 555-6622 | (910) 555-3251 |
-- | (826) 555-1652 | (066) 555-9701 |
-- | (338) 555-6650 | (704) 555-2131 |
-- +----------------+----------------+

-- Narrow down the suspect list using call logs
SELECT name, phone_number, passport_number FROM people
WHERE id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2025
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
        and transaction_type = "withdraw"
    )
)
AND
    phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
    UNION
    SELECT receiver FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- +---------+----------------+-----------------+
-- |  name   |  phone_number  | passport_number |
-- +---------+----------------+-----------------+
-- | Kenny   | (826) 555-1652 | 9878712108      |
-- | Benista | (338) 555-6650 | 9586786673      |
-- | Taylor  | (286) 555-6063 | 1988161715      |
-- | Diana   | (770) 555-1861 | 3592750733      |
-- | Bruce   | (367) 555-5533 | 5773159633      |
-- +---------+----------------+-----------------+

-- Get the information about airports
SELECT * FROM airports;
-- +----+--------------+-----------------------------------------+---------------+
-- | id | abbreviation |                full_name                |     city      |
-- +----+--------------+-----------------------------------------+---------------+
-- | 1  | ORD          | O'Hare International Airport            | Chicago       |
-- | 2  | PEK          | Beijing Capital International Airport   | Beijing       |
-- | 3  | LAX          | Los Angeles International Airport       | Los Angeles   |
-- | 4  | LGA          | LaGuardia Airport                       | New York City |
-- | 5  | DFS          | Dallas/Fort Worth International Airport | Dallas        |
-- | 6  | BOS          | Logan International Airport             | Boston        |
-- | 7  | DXB          | Dubai International Airport             | Dubai         |
-- | 8  | CSF          | Fiftyville Regional Airport             | Fiftyville    |
-- | 9  | HND          | Tokyo International Airport             | Tokyo         |
-- | 10 | CDG          | Charles de Gaulle Airport               | Paris         |
-- | 11 | SFO          | San Francisco International Airport     | San Francisco |
-- | 12 | DEL          | Indira Gandhi International Airport     | Delhi         |
-- +----+--------------+-----------------------------------------+---------------+

-- Check for the details of earliest flight out of fiftyville on 29th of july
SELECT id, hour, minute, destination_airport_id FROM flights
WHERE year = 2025
AND month = 7
AND day = 29
AND origin_airport_id = 8;
-- +----+------+--------+------------------------+
-- | id | hour | minute | destination_airport_id |
-- +----+------+--------+------------------------+
-- | 18 | 16   | 0      | 6                      |
-- | 23 | 12   | 15     | 11                     |
-- | 36 | 8    | 20     | 4                      |
-- | 43 | 9    | 30     | 1                      |
-- | 53 | 15   | 20     | 9                      |
-- +----+------+--------+------------------------+

-- Check for the city where thief escaped to
SELECT * FROM airports
WHERE id = 4;
-- THIEF ESCAPED TO NEW YORK CITY

-- Find the thief using all the information we have so far
SELECT name, phone_number, passport_number FROM people
WHERE id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2025
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
        and transaction_type = "withdraw"
    )
)
AND
    phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
    UNION
    SELECT receiver FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
)
AND
    passport_number IN (
        SELECT passport_number FROM passengers
        WHERE flight_id IN (
            SELECT id FROM flights
            WHERE year = 2025
            AND month = 7
            AND day = 29
            AND origin_airport_id = 8
            AND destination_airport_id = 4
        )
)
AND
license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND (minute > 15 AND minute < 25)
    AND activity = "exit"
);
-- Bruce is the thief
-- +-------+----------------+-----------------+
-- | name  |  phone_number  | passport_number |
-- +-------+----------------+-----------------+
-- | Bruce | (367) 555-5533 | 5773159633      |
-- +-------+----------------+-----------------+

-- Check for accomplice
SELECT name FROM people
WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller = (
        SELECT phone_number FROM people
        WHERE name = "Bruce"
    )
);
