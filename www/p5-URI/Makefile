# $NetBSD: Makefile,v 1.8 2001/03/21 17:15:33 mjl Exp $
#

DISTNAME=	URI-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 class to represent Uniform Resource Identifier (URI, RFC 2396)

BUILD_DEPENDS=	${PERL5_SITEARCH}/auto/MIME/Base64/.packlist:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/URI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
