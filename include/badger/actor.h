#ifndef BADGER_ACTOR_H
#define BADGER_ACTOR_H

#include <badger/sprite_sheet.h>
#include <badger/position.h>
#include <vector>

namespace Badger {

  struct AnimationFrame {
    Sprite* sprite;
    double textureCoordinates[4];
  };

  struct Animation {
    char name[129];
    std::vector<AnimationFrame*> frames;
  };

  class Actor {
    public:
      /*
       *  Constructs a Badger::Actor using the actor files in the
       *    given filepath. The sprite used is defined by the given
       *    Badger::SpriteSheet.
       */
      Actor(const char* actorFile,
            SpriteSheet* spriteSheet,
            unsigned int x,
            unsigned int y);
      ~Actor();

      /*
       *  Return: the Badger::SpriteSheet for the Badger::Actor.
       */
      SpriteSheet* spriteSheet();

      /*
       *  Return: the Badger::Position for the Badger::Actor.
       */
      Position position();

      /*
       *  Sets the current animation to be played by this Badger::Actor.
       */
      void animate(const char* animationName);

      /*
       *  Advances the frame to the next sprite.
       */
      void nextFrame();

      /*
       *  Fills the given array with the texture coordinates of the current
       *    sprite.
       */
      void textureCoordinates(double coords[4]);

      /*
       *  Returns the Badger::Sprite for the current sprite for this
       *    Badger::Actor.
       */
      Sprite* sprite();

      /*
       *  Updates the current time for the Actor. Affects animations and movements.
       */
      void update(double elapsed);

    private:

      // Creates a new animation structure
      Animation* _newAnimation(const char* name);

      // The set of sprites for the Actor.
      SpriteSheet* _spriteSheet;

      // The current position of the Actor in the world.
      Position _position;

      // Stores the details about animations.
      std::vector<Animation*> _animations;

      // Stores the current animation
      Animation* _currentAnimation;

      // Stores the current frame
      unsigned int _currentFrame;
      AnimationFrame* _frame;

      // time since last frame
      double _currentTime;
  };
}

#endif
