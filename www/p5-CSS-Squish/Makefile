# $NetBSD: Makefile,v 1.4 2009/05/21 11:33:32 sno Exp $
#

DISTNAME=	CSS-Squish-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CSS/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Squish/
COMMENT=	Compact many CSS files into one big file
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CSS/Squish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
