# $NetBSD: Makefile,v 1.1.1.1 1998/12/04 00:10:57 tv Exp $
#

DISTNAME=       	mod_perl-1.16
PKGNAME=        	ap-perl-1.16
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://perl.apache.org/

DEPENDS=		libperl-5.00404:../../lang/libperl \
			apache-1.3.3.1:../../www/apache

post-extract:
	@${LN} -sf ../../../Apache/typemap ${WRKSRC}/src/modules/perl/
	@${LN} -sf ${PREFIX}/include/httpd ${WRKSRC}/include
	@for module in Connection File Log ModuleConfig PerlRunXS Tie URI \
		Util Server; do \
		${LN} -sf ../src/modules/perl/$$module.xs ${WRKSRC}/$$module/; \
	done

do-configure:
	@${RM} -f ${WRKSRC}/lib/Apache/src.pm.orig
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} NO_HTTPD=1 \
		APACHE_PREFIX=${PREFIX} ${PREFIX}/bin/perl Makefile.PL

post-build:
	@cd ${WRKSRC}/src/modules/perl && \
	${MAKE} PERL=${PREFIX}/bin/perl STATIC_EXTS="Apache Apache::Constants" \
		Apache.c Constants.c perlxsi.c && \
	PERLLIBDIR=`${PREFIX}/bin/perl -MConfig -e 'print $$Config{archlibexp}'` && \
	${PREFIX}/sbin/apxs -c -o mod_perl.so -I$$PERLLIBDIR/CORE -DMOD_PERL \
		Apache.c Constants.c [mop]*.c $$PERLLIBDIR/DynaLoader_pic.o

post-install:
	@cd ${WRKSRC}/src/modules/perl && ${PREFIX}/sbin/apxs -i mod_perl.so
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_perl
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.add ${PREFIX}/share/doc/mod_perl/

.include "../../mk/bsd.pkg.mk"
