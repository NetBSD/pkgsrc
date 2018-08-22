# $NetBSD: Makefile,v 1.16 2018/08/22 09:48:02 wiz Exp $

DISTNAME=	Clipboard-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KI/KING/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clipboard/
COMMENT=	Copy and paste with any OS
LICENSE=	${PERL5_LICENSE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
DEPENDS+=	xclip-[0-9]*:../../x11/xclip
.endif

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Clipboard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
