# $NetBSD: Makefile,v 1.7 1999/12/02 21:03:35 rh Exp $
#

DISTNAME=       	mod_perl-1.19
PKGNAME=        	ap-perl-1.19
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://perl.apache.org/

DEPENDS+=		libperl-5.*:../../lang/libperl
DEPENDS+=		apache-1.3.*:../../www/apache

USE_PERL5=		yes

MAKE_ENV=		DYNALOADER_OBJ_PIC="${PREFIX}/lib/perl5/${MACHINE_ARCH}-${LOWER_OPSYS}/5.00404/DynaLoader_pic.o"

do-configure:
	@cd ${WRKSRC} && ${PREFIX}/bin/perl Makefile.PL USE_APXS=1 \
		WITH_APXS=${PREFIX}/sbin/apxs EVERYTHING=1

post-install:
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"
