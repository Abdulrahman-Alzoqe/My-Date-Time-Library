# 📅 MY Date & Time Library

A comprehensive, fully custom C++ utility library built from scratch to simplify date manipulation, period management, and calendar rendering. Designed to serve as a robust alternative to standard time libraries, it provides developers with maximum control and flexibility for complex date-time operations without unnecessary overhead.

The library is highly versatile, supporting **Static Methods** (allowing it to function as a stateless Utility Library) as well as an Object-Oriented approach complete with **Smart Properties** for seamless data access.

---

## 🚀 Key Features

*   **🛠️ Stateless Utility System (Static Methods):** Use all powerful date-processing functions directly via the class name (e.g., `ClsDate::CheckLeapYear`) without needing to instantiate an object.
*   **📅 Flexible Constructors (Method Overloading):** Initialize dates in 4 different ways: automatically using the current system date, parsing a formatted string, providing separate day/month/year components, or by specifying the total number of days in a given year.
*   **🗓️ Smart Calendar Rendering:** An internal formatting engine that automatically calculates day alignment and prints fully aligned monthly or yearly calendars directly to the console.
*   **➕/➖ Advanced Date Arithmetic:** Effortlessly increase or decrease dates by precise intervals—including days, weeks, months, years, decades, centuries, and even entire millennia—with built-in boundary handling for changing months and leap years.
*   **⏱️ Period Engine & Overlap Calculations:**
    *   Detect if two timeline periods overlap (`IsOverlapPeriods`).
    *   Calculate the exact number of overlapping days between two distinct periods.
    *   Check if a specific date falls within a given period.
*   **👔 Business Day & Vacation Tracker:**
    *   Identify weekdays, weekends, and specific business days.
    *   Calculate the exact number of actual vacation days between two dates, automatically excluding weekends.
*   **⚙️ String Formatting & Validation:** Seamlessly convert string formats to operational date structures and vice versa, featuring customizable formatting masks like `dd/mm/yyyy`.

---

## 🛠️ Prerequisites

*   A C++ compiler supporting **C++11** or later.
*   An environment supporting Microsoft-specific property extensions (like Visual Studio) if you plan to use the direct property accessors.
*   **Dependency:** This library requires your helper file: **`ClsString.h`** (utilized internally for string tokenization, splitting, and word replacement).
    
    return 0;
}
