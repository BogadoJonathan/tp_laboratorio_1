#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define HTML_INICIAL "<!DOCTYPE html><!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:&bsol;&bsol; -->\n    <!--[if lt IE 9]>\n        <script src='https:&bsol;&bsol;oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https:&bsol;&bsol;oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n"
#define HTML_FINAL "</div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>\0"
#define ARTICLE_INICIO "            <article class='col-md-4 article-intro'>\n"
#define ARTICLE_LINK "                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n"
#define ARTICLE_TITULO "                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n"
#define ARTICLE_LISTA "				<ul>\n					<li>Género:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duración:%d</li>\n				</ul>\n"
#define ARTICLE_DESCRIPCION "                <p>%s</p>\n"
#define ARTICLE_CIERRE "            </article>"

#define MAX_TITULO 50
#define MAX_GENERO 50
#define MAX_DESCRIPCION 140
#define MAX_LINKIMAGEN 300

typedef struct{
int id;
int estado;
char titulo[MAX_TITULO];
char genero[MAX_GENERO];
int duracion;
char descripcion[MAX_DESCRIPCION];
int puntaje;
char linkImagen[MAX_LINKIMAGEN];
}eMovie;

int menu (void);
int ingresarNumero(char mensaje[100], int minimo, int maximo);
void ingresarTexto(char mensaje[100],char *Destino,int desde, int hasta,char ingresarNumeros);
void crearMovie(eMovie movie,eMovie *pMovie, int *contador, int *index);
void printlistMovie (eMovie *movie,int index);
void borrarMovie (eMovie *movie, int index);
void modificarMovie (eMovie *movie, int index);
void generarMovi (eMovie *movie, int index);


#endif // FUNCIONES_H_INCLUDED
