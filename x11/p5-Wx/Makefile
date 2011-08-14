# $NetBSD: Makefile,v 1.14 2011/08/14 07:20:53 obache Exp $
#

DISTNAME=	Wx-0.98
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx/
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	p5-Alien-wxWidgets>=0.25:../../x11/p5-Alien-wxWidgets
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.22.03:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-ExtUtils-XSpp>=0.15:../../devel/p5-ExtUtils-XSpp

#USE_TOOLS+=		gmake pkg-config wx-config
USE_TOOLS+=		perl
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Wx/.packlist

MAKE_PARAMS+=		--wx-toolkit=gtk2

.include "../../lang/perl5/module.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
