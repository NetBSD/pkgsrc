# $NetBSD: Makefile,v 1.48 2017/06/05 14:25:36 ryoon Exp $

DISTNAME=	Wx-0.9928
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx/
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=	p5-Alien-wxWidgets>=0.25:../../x11/p5-Alien-wxWidgets
#BUILD_DEPENDS+=	{perl>=5.16.6,p5-ExtUtils-ParseXS>=3.15}:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-ExtUtils-XSpp>=0.16.02:../../devel/p5-ExtUtils-XSpp

#USE_TOOLS+=		gmake pkg-config wx-config
USE_TOOLS+=		perl
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Wx/.packlist

MAKE_PARAMS+=		--wx-toolkit=gtk2

.include "../../lang/perl5/module.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
