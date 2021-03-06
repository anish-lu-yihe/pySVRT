
/*
 *  svrt is the ``Synthetic Visual Reasoning Test'', an image
 *  generator for evaluating classification performance of machine
 *  learning systems, humans and primates.
 *
 *  Copyright (c) 2017 Idiap Research Institute, http://www.idiap.ch/
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
 *  along with svrt.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

struct VignetteSet {
  int n_problem;
  int nb_vignettes;
  int width;
  int height;
  unsigned char *data;
  int max_shapes;
  int nb_symbolic_outputs;
  unsigned char *nb_shapes_each;
  float *shapes_symb_output;
  unsigned char *intershape_distance;
  float *shape_is_containing;
};

  void svrt_generate_vignettes(int n_problem, int nb_vignettes, long *labels,
                               struct VignetteSet *result);

#ifdef __cplusplus
}
#endif
