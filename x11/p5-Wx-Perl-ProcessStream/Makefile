# $NetBSD: Makefile,v 1.39 2017/06/05 14:25:36 ryoon Exp $

DISTNAME=	Wx-Perl-ProcessStream-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	21
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx-Perl-ProcessStream/
COMMENT=	Access IO of external processes via events from WxWidgets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Wx>=0.50:../../x11/p5-Wx

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Wx/Perl/ProcessStream/.packlist

.include "../../x11/p5-Wx/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
