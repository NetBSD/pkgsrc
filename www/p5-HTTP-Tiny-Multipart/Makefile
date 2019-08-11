# $NetBSD: Makefile,v 1.3 2019/08/11 13:24:48 wiz Exp $

DISTNAME=	HTTP-Tiny-Multipart-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/RENEEB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Tiny-Multipart
COMMENT=	Add post_multipart to HTTP::Tiny
LICENSE=	artistic-2.0

DEPENDS+=	p5-HTTP-Tiny-[0-9]*:../../www/p5-HTTP-Tiny

PERL5_PACKLIST=	auto/HTTP/Tiny/Multipart/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
