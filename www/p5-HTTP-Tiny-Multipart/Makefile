# $NetBSD: Makefile,v 1.4 2020/08/31 18:12:58 wiz Exp $

DISTNAME=	HTTP-Tiny-Multipart-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
