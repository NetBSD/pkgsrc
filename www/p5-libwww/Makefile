# $NetBSD: Makefile,v 1.19 2001/05/14 16:01:22 zuntum Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/14 04:00:11 jfitz Exp
#

DISTNAME=	libwww-perl-5.53
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 library for WWW access

DEPENDS+= 	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-HTML-Parser-*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-*:../../www/p5-URI

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libwww-perl/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
