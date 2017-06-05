# $NetBSD: Makefile,v 1.18 2017/06/05 14:25:24 ryoon Exp $

DISTNAME=	Kwiki-HtmlBlocks-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to display blocks of HTML markup

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/HtmlBlocks/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
