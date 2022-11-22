#include "file.h"

#include <adiar/file_stream.h>

#include <adiar/internal/assert.h>

namespace adiar
{
  template<bool reverse>
  internal::node::label_t extract_label(const node_file &file)
  {
    adiar_debug(file.size() > 0, "Invalid node_file: empty");

    node_stream<reverse> ns(file);
    internal::node n = ns.pull();

    adiar_debug(!n.is_terminal(), "Cannot extract label from terminal-only file");

    return n.label();
  }

  internal::node::label_t min_label(const node_file &file)
  {
    return extract_label<false>(file);
  }

  internal::node::label_t max_label(const node_file &file)
  {
    return extract_label<true>(file);
  }
}
