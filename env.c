#include "main.h"


char *get_env (const char *env_name)
{
	int len = 0;
	int i;
	char *_env;
	for (i = 0; environ[i]; i++)
	{
		_env = environ[i];
		len = _strlen(env_name);
		
		if (strncmp(_env, env_name, len) == 0 && _env[len] == '=')
			return (&_env[len + 1]);
	}
	return (NULL);
}
