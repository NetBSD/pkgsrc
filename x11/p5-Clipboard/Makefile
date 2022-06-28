# $NetBSD: Makefile,v 1.23 2022/06/28 11:37:56 wiz Exp $

DISTNAME=	Clipboard-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHLOMIF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Clipboard
COMMENT=	Copy and paste with any OS
LICENSE=	${PERL5_LICENSE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
DEPENDS+=	xclip-[0-9]*:../../x11/xclip
.endif

PERL5_PACKLIST=		auto/Clipboard/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
