# $NetBSD: Makefile,v 1.24 2021/05/24 19:55:54 wiz Exp $

DISTNAME=	WWW-Facebook-API-0.4.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Facebook-API
COMMENT=	Facebook API implementation

DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-JSON-Any-[0-9]*:../../converters/p5-JSON-Any
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly

PERL5_PACKLIST=		auto/WWW/Facebook/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
