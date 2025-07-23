# Ground Vehicle Simulation Environment (GVSE)
GVSE is meant to be a cross-platform, small, lightweight, environment agnostic 2D GUI visualization environment. The primary objective so to be minimal such that its simple and intuitive to use, but also provide critical insights into the state of what is being visualed.

This tool is being has both a standalone executable and an exposed interface to be included in other projects [GMSE](https://github.com/alexb7711/GMSE)).

The interface is defined by transmitting data via UDP/TPC serialized in a JSON format or by providing the data to the object directly. Note that these interfaces are still in the process of being defined, but this provides the general intent of the interface.

## Visualization Objectives
- [ ] Visualize vehicle world position and orientation
- [ ] Visualize obstacles
- [ ] Visualize path
- [ ] Provided a table of state data
- [ ] Allow the state data to be modified
- [ ] Allow data to be plotted over time
