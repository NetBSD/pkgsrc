# $NetBSD: Makefile,v 1.9 2000/08/27 22:40:36 jlam Exp $
#

DISTNAME=		mod_perl-1.24
PKGNAME=		ap-perl-1.24
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://perl.apache.org/

DEPENDS+=		libperl-5.*:../../lang/libperl
DEPENDS+=		apache{,6}-1.3.*:../../www/apache

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${PREFIX}/sbin/apxs
MAKE_PARAMS+=		EVERYTHING=1

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"

.if exists(${PERL5_ARCHLIB}/DynaLoader_pic.o)
MAKE_ENV+=		DYNALOADER_OBJ_PIC="${PERL5_ARCHLIB}/DynaLoader_pic.o"
.endif
