#include "./events.hpp"

#include <algorithm>

namespace rchess
{
	void handle_case_click(Board *board, int x, int y)
	{
		reset_selected_piece(board);
		const auto current_selected_piece = board->get_selected_piece();
		const auto pieces = board->get_pieces();
		auto new_selected_piece = std::find_if(pieces.begin(),
			pieces.end(),
			[&](const std::shared_ptr<Piece> piece) { return piece->get_x() == x && piece->get_y() == y; });

		if (new_selected_piece == pieces.end())
		{
			if (current_selected_piece != nullptr)
			{
				move_piece_position(current_selected_piece, x, y);
			}
			return;
		}
		board->set_selected_piece(*new_selected_piece);
		new_selected_piece->get()->do_re_render();
	}

	void reset_selected_piece(Board *board)
	{
		board->set_selected_piece(nullptr);
	}

	void move_piece_position(std::shared_ptr<Piece> piece, int x, int y)
	{
		piece->set_position(sdlk::Position(x, y));
		piece->do_re_render();
	}
}  // namespace rchess
