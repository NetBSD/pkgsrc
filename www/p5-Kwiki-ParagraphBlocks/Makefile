# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:47 jlam Exp $

DISTNAME=      	Kwiki-ParagraphBlocks-0.12
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to display paragraphs with embedded whitespace

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/ParagraphBlocks/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
