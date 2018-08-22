# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:46 wiz Exp $

DISTNAME=	Kwiki-Notify-Mail-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki email notification plugin

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki
DEPENDS+=	p5-MIME-Lite>=2.111:../../mail/p5-MIME-Lite

PERL5_PACKLIST=	auto/Kwiki/Notify/Mail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
