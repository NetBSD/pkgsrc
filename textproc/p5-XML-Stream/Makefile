# $NetBSD: Makefile,v 1.1.1.1 2003/09/18 08:33:12 xtraeme Exp $
#

DISTNAME=	XML-Stream-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xmlstream/
COMMENT=	XML::Stream provides you with access to XML Stream

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String

USE_BUILDLINK2=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Stream/.packlist

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
