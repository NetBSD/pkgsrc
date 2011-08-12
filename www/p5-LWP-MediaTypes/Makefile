# $NetBSD: Makefile,v 1.4 2011/08/12 09:25:47 obache Exp $

DISTNAME=	LWP-MediaTypes-6.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-MediaTypes/
COMMENT=	guess media type for a file or a URL
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/MediaTypes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
