# $NetBSD: Makefile,v 1.11 1999/12/02 15:16:19 rh Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/14 04:00:11 jfitz Exp
#

PKGNAME=       	p5-libwww-5.46
DISTNAME!=     	echo ${PKGNAME} | sed -e 's/^p5-//' -e 's/-/-perl-/'
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	packages@netbsd.org

DEPENDS+= 	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Net-*:../../net/p5-Net
DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-HTML-Parser-*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-*:../../www/p5-URI

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
