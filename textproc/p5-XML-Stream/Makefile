# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:50 jlam Exp $
#

DISTNAME=	XML-Stream-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xmlstream/
COMMENT=	XML::Stream provides you with access to XML Stream

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String

PERL5_PACKLIST=	auto/XML/Stream/.packlist

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
