# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:27 joerg Exp $

DISTNAME=      	Kwiki-Scode-0.03
PKGNAME=       	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki Scode plugin to protect against wiki spammers

DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-Kwiki>=0.36:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Scode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
