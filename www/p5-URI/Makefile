# $NetBSD: Makefile,v 1.19 2003/01/31 10:40:35 shell Exp $
#

DISTNAME=	URI-1.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5uri
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 class to represent Uniform Resource Identifier (URI, RFC 2396)

BUILD_DEPENDS=	p5-MIME-Base64>=2.12:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
