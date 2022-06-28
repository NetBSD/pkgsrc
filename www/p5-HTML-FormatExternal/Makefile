# $NetBSD: Makefile,v 1.2 2022/06/28 11:37:22 wiz Exp $

DISTNAME=	HTML-FormatExternal-26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KR/KRYDE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-FormatExternal
COMMENT=	HTML to text formatting using external programs
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-constant-defer-[0-9]*:../../devel/p5-constant-defer
DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/HTML/FormatExternal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
