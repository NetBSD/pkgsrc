# $NetBSD: Makefile,v 1.3 2000/07/03 09:36:13 mjl Exp $
#

DISTNAME=	URI-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS= 	${PREFIX}/lib/perl5/site_perl/MIME/Base64.pm:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
