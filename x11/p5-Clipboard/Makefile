# $NetBSD: Makefile,v 1.3 2009/07/07 17:19:37 sno Exp $
#

DISTNAME=	Clipboard-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KI/KING/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clipboard/
COMMENT=	Copy and paste with any OS
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
.endif

DEPENDS+=	p5-Spiffy-[0-9]*:../../devel/p5-Spiffy
DEPENDS+=	xclip-[0-9]*:../../x11/xclip

PERL5_PACKLIST=		auto/Clipboard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
