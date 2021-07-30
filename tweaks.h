#ifndef __TWEAKS_H
#define __TWEAKS_H

struct theme {
	char *name;
	char *path;
};

struct themes {
	struct theme *data;
	int nr, alloc;
};

void find_themes(struct themes *themes, const char *path, const char *filename);

void xml_init(const char *filename);
void xml_save(void);
void xml_finish(void);
void xml_set(char *nodename, char *value);
void xml_set_num(char *nodename, double value);
char *xml_get(char *nodename);
int xml_get_int(char *nodename);

#endif /* __TWEAKS_H */