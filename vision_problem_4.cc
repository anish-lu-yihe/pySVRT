/*
 *  svrt is the ``Synthetic Visual Reasoning Test'', an image
 *  generator for evaluating classification performance of machine
 *  learning systems, humans and primates.
 *
 *  Copyright (c) 2009 Idiap Research Institute, http://www.idiap.ch/
 *  Written by Francois Fleuret <francois.fleuret@idiap.ch>
 *
 *  This file is part of svrt.
 *
 *  svrt is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 *
 *  svrt is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with pysvrt.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "vision_problem_4.h"
#include "shape.h"

VisionProblem_4::VisionProblem_4() { }

void VisionProblem_4::generate(int label, Vignette *vignette) {
  int x_big, y_big, x_small, y_small;
  Shape big_shape, small_shape;

  int error;
  do {

    vignette->clear();

    error = 0;

    big_shape.randomize(big_part_size / 2, big_part_hole_size / 2);

    do {
      x_big = int(random_uniform_0_1() * Vignette::width);
      y_big = int(random_uniform_0_1() * Vignette::height);
    } while(big_shape.overwrites(vignette, x_big, y_big));

    if(!error) {
      big_shape.draw(0, vignette, x_big, y_big);

      vignette->fill(x_big, y_big, 128);

      if(label) {
        vignette->switch_values(128, 255);
      }

      int nb_attempts = 0;
      do {
        small_shape.randomize(small_part_size / 2, small_part_hole_size / 2);
        x_small = int(random_uniform_0_1() * Vignette::width);
        y_small = int(random_uniform_0_1() * Vignette::height);
        error = small_shape.overwrites(vignette, x_small, y_small);
        nb_attempts++;
      } while(error && nb_attempts < 10);

      if(!error) {
        vignette->replace_value(128, 255);
        small_shape.draw(1, vignette, x_small, y_small);
      }
    }

  } while(error);
}
