# $NetBSD: Makefile,v 1.8 2011/08/14 16:05:46 obache Exp $
#

DISTNAME=	CSS-Squish-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CSS/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Squish/
COMMENT=	Compact many CSS files into one big file
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CSS/Squish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
