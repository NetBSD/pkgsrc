# $NetBSD: Makefile,v 1.4 2011/08/12 09:25:47 obache Exp $

DISTNAME=	LWP-Protocol-https-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-Protocol-https/
COMMENT=	Provide https support for LWP::UserAgent
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.02

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/https/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
