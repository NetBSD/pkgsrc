# $NetBSD: Makefile,v 1.23 2003/11/27 16:34:48 grant Exp $
#

DISTNAME=	URI-1.27
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5uri
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 Uniform Resource Identifiers class (URI, RFC 2396)

BUILD_DEPENDS=	p5-MIME-Base64>=2.12:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
