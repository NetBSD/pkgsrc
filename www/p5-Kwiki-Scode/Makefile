# $NetBSD: Makefile,v 1.19 2016/06/08 19:25:10 wiz Exp $

DISTNAME=	Kwiki-Scode-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki Scode plugin to protect against wiki spammers

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-Kwiki>=0.36:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Scode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
