# $NetBSD: Makefile,v 1.3 2010/03/02 14:27:25 sno Exp $
#

DISTNAME=	Wx-Perl-ProcessStream-0.27
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx-Perl-ProcessStream/
COMMENT=	Access IO of external processes via events from WxWidgets
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Wx/Perl/ProcessStream/.packlist

.include "../../x11/p5-Wx/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
