# $NetBSD: Makefile,v 1.1.1.1 1999/12/02 08:34:33 rh Exp $
#

PKGNAME=       	p5-URI-1.04
DISTNAME!=     	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
