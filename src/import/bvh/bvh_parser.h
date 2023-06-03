#ifndef MCMV_CORE_PARSER_H
#define MCMV_CORE_PARSER_H

#include "bvh_lexer.h"
#include "../armature_importer.h"

enum class ChannelOrder {
  Xposition,
  Yposition,
  Zposition,
  Xrotation,
  Yrotation,
  Zrotation

};

class BvhParser {
 public:
  explicit BvhParser(BvhLexer *lexer);

  ~BvhParser();

  vector<Joint> *get_model();

  vector<JointMotion *> *get_animation_frames();

 private:
  BvhToken current_token = tok_eof;
  BvhToken next_token = tok_start;

  string current_string;
  string next_string;

  BvhLexer *lexer;

  vector<vector<ChannelOrder>> order;

  bool parse();

  void update_token();
  vector<Joint> *model = nullptr;
  vector<JointMotion *> *animation_frames = nullptr;

  void parse_model();
  void handle_root();
  void handle_joint();
};

#endif //MCMV_CORE_PARSER_H