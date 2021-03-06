#ifndef JVCR_ECM_01_MACHINE_H
#define JVCR_ECM_01_MACHINE_H

#include <jvcr_ecm_01/types.h>
#include <jvcr_ecm_01/consts.h>

/**
 * This structure contains openGL info
 */
typedef struct JvcrDisplay {
  // TODO: actually this types is rendering system specific. How to incapsulate it into the implementation?
  byte *texture;
  unsigned int texture_id;
} JvcrDisplay;

typedef struct JvcrRam {
  byte *memory;
} JvcrRam;

typedef struct Jvcr {
  JvcrRam *ram;
  JvcrDisplay *display;
  double time;
  void (*onDraw)(struct Jvcr*, double); // called once per visible frame
  void (*onUpdate)(struct Jvcr*, double); // called once per update at 30fps
  void (*onUpdate60)(struct Jvcr*, double); // called once per update at 60fps
  void (*onInit)(struct Jvcr*); // Called once on program startup
  void (*onDestroy)(struct Jvcr*); // Called once on program just before it's been destroyed
} Jvcr;

Jvcr* NewJvcr();
void DestroyJvcr(Jvcr*);

JvcrRam* NewJvcrRam();
void DestroyJvcrRam(JvcrRam*);

JvcrDisplay* NewJvcrDisplay();
void DestroyJvcrDisplay(JvcrDisplay*);

void RunLoop(Jvcr *);

#endif //JVCR_ECM_01_MACHINE_H
