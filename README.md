# Histogram [![codecov](https://codecov.io/gh/vetlewi/Logger/branch/main/graph/badge.svg?token=TFfYJx7sKW)](https://codecov.io/gh/vetlewi/Logger)[![MacOS](https://github.com/vetlewi/Logger/actions/workflows/macos.yml/badge.svg)](https://github.com/vetlewi/Logger/actions/workflows/macos.yml) [![Ubuntu](https://github.com/vetlewi/Logger/actions/workflows/Ubuntu.yml/badge.svg)](https://github.com/vetlewi/Logger/actions/workflows/Ubuntu.yml) [![Install](https://github.com/vetlewi/Logger/actions/workflows/install.yml/badge.svg)](https://github.com/vetlewi/Logger/actions/workflows/install.yml)
This package contains a simple library to provide a simple histogram data type.

### Usage:
If you use CPM the library are easily imported by
````cmake
CPMAddPackage("gh:vetlewi/Logger@1.0.0")
````

### TODO:
- The target for the logger should not be determined by which stream is used by the user. As it is now this is more of a formatter. Will need to work on this in the future.