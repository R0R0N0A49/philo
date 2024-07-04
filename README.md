# pthread_create

- permat de cree un thread et de lancer une fonction en parallèle de la fonction principal

# pthread_detach

- permet de dire au thread qui doit attendre apres avoir fini

# pthread_join

- permat de dire aux thread de revenir dans la fonction principal quand il a terminer

# pthread_mutex_init

- permet de cree une variable securiser ou un seul thread a la foix peut avoir acces

# pthread_mutex_destroy

- permet de destroy un mutex (en fin de programme)

# pthread_mutex_lock

- permet de lock un mutex pendent sont utilisation pour que les autre thread ny est pas acces.
	les thread demandant l'acces vont attendre un unlock (et ne rien faire d'autre) si le mutex est deja utiliser

# pthread_mutex_unlock

- permet de unlock un mutex pour dire que la fonction ne l'utilise plus et qu'un autre thread peut y avoir acces.
