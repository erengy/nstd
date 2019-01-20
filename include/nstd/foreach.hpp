#pragma once

namespace nstd {

// iterator
#define foreach_(it, container) \
    for (auto it = (container).begin(); it != (container).end(); ++it)

// reverse iterator
#define foreach_r_(it, container) \
    for (auto it = (container).rbegin(); it != (container).rend(); ++it)

// const iterator
#define foreach_c_(it, container) \
    for (auto it = (container).cbegin(); it != (container).cend(); ++it)

// const reverse iterator
#define foreach_cr_(it, container) \
    for (auto it = (container).crbegin(); it != (container).crend(); ++it)

}  // namespace nstd
