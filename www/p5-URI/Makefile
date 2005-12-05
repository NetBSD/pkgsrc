# $NetBSD: Makefile,v 1.31 2005/12/05 20:51:13 rillig Exp $
#

DISTNAME=	URI-1.35
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5uri
PKGREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/URI/
COMMENT=	Perl5 Uniform Resource Identifiers class (URI, RFC 2396)

BUILD_DEPENDS+=	p5-MIME-Base64>=2.12:../../converters/p5-MIME-Base64

CONFLICTS+=	p5-libwww-5.36	# URI used to be part of that package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
