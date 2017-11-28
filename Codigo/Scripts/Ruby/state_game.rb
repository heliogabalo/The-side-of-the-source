class Game
  def initialize
    @state = GameState.new(...)
  end

  def play_turn
    display state
    get user input
    perform calculations
    update state
  end
end

# main
game = Game.new
until game.is_over? do
  game.play_turn
end
